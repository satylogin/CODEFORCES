use std::collections::VecDeque;

fn assign(graph: Vec<Vec<usize>>, n: usize) -> Vec<usize> {
    let mut color: Vec<usize> = vec![0; n + 1];
    let mut white: VecDeque<usize> = VecDeque::new();
    let mut potential_black: VecDeque<usize> = VecDeque::new();
    potential_black.push_back(1);
    while let Some(x) = potential_black.pop_front() {
        if color[x] > 1 {
            continue;
        }
        color[x] = 2;
        for &y in graph[x].iter() {
            if color[y] < 2 {
                color[y] = 3;
                white.push_back(y);
            }
        }
        while let Some(y) = white.pop_front() {
            for &x in graph[y].iter() {
                if color[x] == 0 {
                    color[x] = 1;
                    potential_black.push_back(x);
                }
            }
        }
    }
    color
}

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let n: usize = sc.next();
        let m: usize = sc.next();
        let mut graph: Vec<Vec<usize>> = vec![vec![]; n + 1];
        for _ in 0..m {
            let x: usize = sc.next();
            let y: usize = sc.next();
            graph[x].push(y);
            graph[y].push(x);
        }
        let color: Vec<usize> = assign(graph, n);
        let mut invalid: usize = 0;
        let mut teachers: usize = 0;
        for &x in color[1..].iter() {
            invalid += (x < 2) as usize;
            teachers += (x == 2) as usize;
        }
        if invalid == 0 {
            writeln!(out, "YES").unwrap();
            writeln!(out, "{}", teachers).unwrap();
            (1..=n).for_each(|i| if color[i] == 2 {write!(out, "{} ", i).unwrap()});
            writeln!(out).unwrap();
        } else {
            writeln!(out, "NO").unwrap();
        }
    }
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
