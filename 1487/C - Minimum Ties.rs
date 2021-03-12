use std::io::{self, Write};
use std::collections::HashMap;

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let n: i32 = sc.next();
        let mut tot = n * (n - 1) / 2;
        let mut result: HashMap<(i32, i32), i32> = HashMap::new();
        let mut diff = 1;
        while tot >= n {
            for i in 0..n {
                result.insert((i, (i + diff) % n), i);
            }
            tot -= n;
            diff += 1;
        }
        for i in 0..n {
            for j in i+1..n {
                let winner = if result.contains_key(&(i, j)) {
                    result.get(&(i, j))
                } else {
                    result.get(&(j, i))
                };
                if let Some(&winner) = winner {
                    write!(out, "{} ", if winner == i {1} else {-1}).unwrap();
                } else {
                    write!(out, "0 ").unwrap();
                }
            }
        }
        writeln!(out).unwrap();
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
