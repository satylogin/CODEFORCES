use std::collections::BTreeSet;
use std::collections::vec_deque::VecDeque;

#[derive(Debug)]
struct Node {
    weak_edge: BTreeSet<usize>,
    strong_edge: BTreeSet<usize>,
}

impl Clone for Node {
    fn clone(&self) -> Self {
        Node {
            weak_edge: self.weak_edge.clone(),
            strong_edge: self.strong_edge.clone(),
        }
    }
}

fn get_in_degree(dag: &Vec<Node>) -> Vec<usize> {
    let mut in_degree: Vec<usize> = vec![0; dag.len()];
    for i in 1..dag.len() {
        dag[i].weak_edge.iter().for_each(|x| in_degree[*x] += 1);
        dag[i].strong_edge.iter().for_each(|x| in_degree[*x] += 1);
    }
    in_degree
}

fn get_parent_in_strong_dag(dag: &Vec<Node>) -> Vec<usize> {
    let mut in_degree: Vec<usize> = get_in_degree(&dag);
    let mut parent: Vec<usize> = (0..dag.len()).collect();
    let mut queue: VecDeque<usize> = VecDeque::with_capacity(dag.len());
    for i in 1..dag.len() {
        if in_degree[i] == 0 {
            queue.push_back(i);
        }
    }
    while !queue.is_empty() {
        let x: usize = queue.pop_front().unwrap();
        for &y in dag[x].weak_edge.iter() {
            in_degree[y] -= 1;
            if in_degree[y] == 0 {
                queue.push_back(y);
            }
        }
        for &y in dag[x].strong_edge.iter() {
            parent[y] = parent[x];
            in_degree[y] -= 1;
            if in_degree[y] == 0 {
                queue.push_back(y);
            }
        }
    }
    parent
}

fn reassign_edge(mut dag: Vec<Node>) -> Vec<Node> {
    let parent: Vec<usize> = get_parent_in_strong_dag(&dag);
    for x in 1..dag.len() {
        let nodes: Vec<usize> = dag[x].weak_edge.iter().map(|x| *x).collect();
        dag[x].weak_edge.clear();
        for y in nodes {
            if parent[y] != parent[x] {
                dag[x].weak_edge.insert(parent[y]);
            }
        }
        let nodes: Vec<usize> = dag[x].strong_edge.iter().map(|x| *x).collect();
        for y in nodes {
            dag[x].weak_edge.remove(&y);
        }
    }
    dag
}

fn get_path(dag: Vec<Node>) -> Vec<usize> {
    let dag = reassign_edge(dag);
    let mut in_degree: Vec<usize> = get_in_degree(&dag);
    let mut path: Vec<usize> = vec![];
    let mut queue: VecDeque<usize> = VecDeque::with_capacity(dag.len());
    queue.push_back(*dag[0].weak_edge.iter().next().unwrap());
    while !queue.is_empty() {
        let x: usize = queue.pop_front().unwrap();
        if dag[x].strong_edge.len() > 1 {
            return vec![];
        }
        for &y in dag[x].weak_edge.iter() {
            in_degree[y] -= 1;
            if in_degree[y] == 0 {
                queue.push_back(y);
            }
        }
        for &y in dag[x].strong_edge.iter() {
            in_degree[y] -= 1;
            if in_degree[y] == 0 {
                queue.push_front(y);
            } else {
                return vec![];
            }
        }
        path.push(x.clone());
    }
    path
}

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let (n, m) = (sc.next::<usize>(), sc.next::<usize>());
    let mut dag: Vec<Node> = vec![
        Node{
            weak_edge: BTreeSet::new(),
            strong_edge: BTreeSet::new()
        };
        n+1
    ];
    for x in 1..n + 1 {
        dag[sc.next::<usize>()].weak_edge.insert(x);
    }
    for _ in 0..m {
        let (x, y) = (sc.next::<usize>(), sc.next::<usize>());
        dag[x].strong_edge.insert(y.clone());
        dag[x].weak_edge.remove(&y);
    }
    let path: Vec<usize> = get_path(dag);
    if path.len() != n {
        writeln!(out, "{}", 0).unwrap();
    } else {
        path.iter().for_each(|x| write!(out, "{} ", x).unwrap());
        writeln!(out, "").unwrap();
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
