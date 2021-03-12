use std::collections::{BTreeMap, BTreeSet};
use std::io::{self, Write};

fn update_scores(
    a: Vec<usize>,
    b: Vec<usize>,
    edge: BTreeMap<usize, BTreeSet<usize>>,
) -> Vec<usize> {
    let mut idx: Vec<usize> = (0..a.len()).collect();
    idx.sort_by(|x, y| a[*x].cmp(&a[*y]));
    let mut inc: Vec<usize> = vec![idx[0]; b.len()];
    for i in 0..a.len() {
        for &j in edge.get(&idx[i]).unwrap_or(&BTreeSet::new()) {
            if inc[j] == idx[i] {
                inc[j] = if i + 1 == a.len() {
                    usize::MAX
                } else {
                    idx[i + 1]
                };
            }
        }
    }
    let ans: Vec<usize> = (0..b.len())
        .map(|i| {
            if inc[i] == usize::MAX || a[inc[i]] == usize::MAX {
                usize::MAX
            } else {
                b[i] + a[inc[i]]
            }
        })
        .collect();
    ans
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let n: Vec<usize> = sc.next_vec(4);
    let (a, mut b, mut c, mut d) = (
        sc.next_vec(n[0]),
        sc.next_vec(n[1]),
        sc.next_vec(n[2]),
        sc.next_vec(n[3]),
    );

    b = update_scores(a, b, sc.next_edge());
    c = update_scores(b, c, sc.next_edge());
    d = update_scores(c, d, sc.next_edge());

    let ans: usize = d.into_iter().min().unwrap();
    writeln!(out, "{}", if ans == usize::MAX { -1 } else { ans as i32 }).unwrap();
}

#[allow(dead_code)]
mod cf_scanner {
    use std::collections::{BTreeMap, BTreeSet};
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

        pub fn next_vec<T: FromStr>(&mut self, n: usize) -> Vec<T> {
            (0..n).map(|_| self.next()).collect()
        }

        pub fn next_edge(&mut self) -> BTreeMap<usize, BTreeSet<usize>> {
            let m: usize = self.next();
            let mut edge: BTreeMap<usize, BTreeSet<usize>> = BTreeMap::new();
            for _ in 0..m {
                let (x, y): (usize, usize) = (self.next(), self.next());
                edge.entry(x - 1).or_insert(BTreeSet::new()).insert(y - 1);
            }
            edge
        }
    }
}
