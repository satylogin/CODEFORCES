static MOD: i64 = 1000000007;

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let n: usize = sc.next();
        let mut bit_freq: Vec<i64> = vec![0; 100];
        let arr: Vec<i64> = (0..n).map(|_| sc.next()).collect();
        for &x in arr.iter() {
            for i in 0..60 {
                bit_freq[i] += (x>>i) & 1;
            }
        }
        let mut ans: i64 = 0;
        for &x in arr.iter() {
            let mut sum_or: i64 = 0;
            let mut sum_and: i64 = 0;
            for j in 0..60 {
                if (x >> j) & 1 == 1 {
                    sum_and += (1 << j) % MOD * bit_freq[j];
                    sum_or += (1 << j) % MOD * n as i64;
                } else {
                    sum_or += (1 << j) % MOD * bit_freq[j];
                }
            }
            sum_and %= MOD;
            sum_or %= MOD;
            ans += (sum_and * sum_or) % MOD;
        }
        ans %= MOD;
        writeln!(out, "{}", ans).unwrap();
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
