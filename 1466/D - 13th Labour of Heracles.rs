use std::collections::BTreeSet;

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let n: usize = sc.next();
        let mut weight: Vec<i64> = vec![0; n+1];
        (1..=n).for_each(|i| weight[i] = sc.next());
        let mut degree: Vec<i32> = vec![0; n+1];
        for _ in 1..n {
            let x: usize = sc.next();
            let y: usize = sc.next();
            degree[x] += 1;
            degree[y] += 1;
        }
        let mut ans: Vec<i64> = vec![0; n+1];
        ans[1] = weight.iter().sum();
        let mut nodes: BTreeSet<(i64, usize)> = BTreeSet::new();
        for i in 1..=n {
            nodes.insert((-weight[i], i));
        }
        for i in 2..n {
            while !nodes.is_empty() {
                let (x, y) = nodes.iter().next().unwrap().clone();
                if degree[y] < 2 {
                    nodes.remove(&(x, y));
                } else {
                    break;
                }
            }
            ans[i] = 0;
            if let Some(v) = nodes.iter().next() {
                ans[i] = -v.0;
                degree[v.1] -= 1;
            }
            ans[i] += ans[i-1];
        }
        (1..n).for_each(|i| write!(out, "{} ", ans[i]).unwrap());
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
