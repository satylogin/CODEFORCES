use std::collections::BTreeMap;

mod ds {
    use std::collections::{BTreeMap, BTreeSet};
    use std::cmp::Ordering::{Less, Greater};

    #[derive(Debug)]
    pub struct Graph {
        pub graph: Vec<Vec<usize>>,
        pub parent: Vec<usize>,
        pub tin: Vec<usize>,
        pub tout: Vec<usize>,
        pub euler: Vec<usize>,
        pub time: usize,
        pub val: Vec<usize>,
        pub times: BTreeMap<usize, Vec<usize>>,
        pub edges: BTreeSet<(usize, usize)>,
        pub dp: Vec<usize>,
        pub ans: usize
    }

    impl Graph {
        pub fn new(n: usize) -> Graph {
            Graph {
                graph: vec![vec![]; n + 1],
                parent: vec![0; n + 1],
                tin: vec![0; n + 1],
                tout: vec![0; n + 1],
                euler: vec![0; 2 * n - 1],
                time: 0,
                val: vec![0; n + 1],
                times: BTreeMap::new(),
                edges: BTreeSet::new(),
                dp: vec![0; n + 1],
                ans: 0
            }
        }

        pub fn dfs(&mut self, x: usize) {
            self.tin[x] = self.time;
            self.euler[self.time] = x;
            self.time += 1;
            for y in self.graph[x].clone() {
                if y != self.parent[x] {
                    self.parent[y] = x;
                    self.dfs(y);
                    self.euler[self.time] = x;
                    self.time += 1;
                }
            }
            self.tout[x] = self.time - 1;
        }

        pub fn examine(&mut self, x: usize) {
            let mut sum: usize = 0;
            for y in self.graph[x].clone() {
                if y != self.parent[x] {
                    let mut count = self.times[&self.val[x]].binary_search_by(|a| {
                        if *a <= self.tout[y] {Less} else {Greater}
                    }).err().unwrap();
                    count -= self.times[&self.val[x]].binary_search_by(|a| {
                        if *a < self.tin[y] {Less} else {Greater}
                    }).err().unwrap();
                    if count > 0 {
                        self.edges.insert((x, y));
                    }
                    sum += count;
                }
            }
            if self.times[&self.val[x]].len() - sum - 1 > 0 {
                self.edges.insert((x, self.parent[x]));
            }
        }

        pub fn setup(&mut self, x: usize) -> usize {
            for y in self.graph[x].clone() {
                if y != self.parent[x] {
                    self.dp[x] += self.setup(y);
                }
            }
            self.dp[x] + self.edges.contains(&(x, self.parent[x])) as usize
        }

        pub fn reroot(&mut self, x: usize) {
            if self.dp[x] == self.edges.len() {
                self.ans += 1;
            }
            for y in self.graph[x].clone() {
                if y != self.parent[x] {
                    self.dp[x] -= self.dp[y];
                    self.dp[x] -= self.edges.contains(&(y, x)) as usize;
                    self.dp[y] += self.dp[x];
                    self.dp[y] += self.edges.contains(&(x, y)) as usize;

                    self.reroot(y);

                    self.dp[y] -= self.edges.contains(&(x, y)) as usize;
                    self.dp[y] -= self.dp[x];
                    self.dp[x] += self.edges.contains(&(y, x)) as usize;
                    self.dp[x] += self.dp[y];
                }
            }
        }
    }
}

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let n: usize = sc.next();
    let mut graph: ds::Graph = ds::Graph::new(n);
    let mut val_map: BTreeMap<usize, Vec<usize>> = BTreeMap::new();
    for i in 1..=n {
        graph.val[i] = sc.next();
        val_map.entry(graph.val[i]).or_insert(vec![]).push(i);
    }
    for _ in 1..n {
        let (x, y): (usize, usize) = (sc.next(), sc.next());
        graph.graph[x].push(y);
        graph.graph[y].push(x);
    }
    graph.dfs(1);
    for (&x, v) in val_map.iter() {
        if v.len() > 1 {
            for &y in v.iter() {
                graph.times.entry(x).or_insert(vec![]).push(graph.tin[y]);
            }
            graph.times.get_mut(&x).unwrap().sort();
            for &y in v.iter() {
                graph.examine(y);
            }
        }
    }
    graph.setup(1);
    graph.reroot(1);
    writeln!(out, "{}", graph.ans).unwrap();
}

#[allow(dead_code)]
mod cf_scanner {
    use std::io;
    use std::str::{FromStr, SplitAsciiWhitespace};

    pub struct Scanner<R> {
        reader: R,
        buf_str: Vec<u8>,
        buf_iter: SplitAsciiWhitespace<'static>,
    }

    impl<R: io::BufRead> Scanner<R> {
        pub fn new(reader: R) -> Scanner<R> {
            Scanner {
                reader,
                buf_str: Vec::new(),
                buf_iter: "".split_ascii_whitespace(),
            }
        }

        pub fn next<T: FromStr>(&mut self) -> T {
            loop {
                if let Some(token) = self.buf_iter.next() {
                    return token.parse().ok().expect("Failed parse");
                }
                self.buf_str.clear();
                self.reader
                    .read_until(b'\n', &mut self.buf_str)
                    .expect("Failed read");
                self.buf_iter = unsafe {
                    let slice = std::str::from_utf8_unchecked(&self.buf_str);
                    std::mem::transmute(slice.split_ascii_whitespace())
                }
            }
        }
    }
}
