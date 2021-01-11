mod ds {
    pub struct DSU {
        parent: Vec<usize>
    }

    impl DSU {
        pub fn new(n: usize) -> DSU {
            DSU {
                parent: (0..=n).collect()
            }
        }

        pub fn find(&mut self, x: usize) -> usize {
            if x != self.parent[x] {
                self.parent[x] = self.find(self.parent[x]);
            }
            self.parent[x]
        }

        pub fn unite(&mut self, x: usize, y: usize) -> bool {
            let px = self.find(x);
            let py = self.find(y);
            if px != py {
                self.parent[px] = py;
                true
            } else {
                false
            }
        }
    }
}

static MOD: i64 = 1e9 as i64 + 7;
fn bin_expo(mut a: i64, mut b: i64) -> i64 {
    let mut ans: i64 = 1;
    while b > 0 {
        if b & 1 == 1 {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    ans
}

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let n: usize = sc.next();
    let m: usize = sc.next();

    let mut keep: Vec<usize> = vec![];
    let mut dsu: ds::DSU = ds::DSU::new(m);
    for i in 1..=n {
        let k: usize = sc.next();
        let x: usize = sc.next();
        let y: usize = if k == 1 {0} else {sc.next()};
        if dsu.unite(x, y) {
            keep.push(i);
        }
    }
    writeln!(out, "{} {}", bin_expo(2, keep.len() as i64), keep.len()).unwrap();
    keep.iter().for_each(|&x| write!(out, "{} ", x).unwrap());
    writeln!(out).unwrap();
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
