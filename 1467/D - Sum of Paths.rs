static MOD: i64 = 1e9 as i64 + 7;

fn generate_freq(n: usize, k: usize) -> Vec<i64> {
    let mut freq: Vec<i64> = vec![0; n + 2];
    let mut state_freq: Vec<Vec<i64>> = vec![vec![0; n + 2]; k + 1];
    state_freq[0] = vec![1; n + 1];
    for i in 0..k {
        for j in 1..=n {
            state_freq[i+1][j+1] = (state_freq[i+1][j+1] + state_freq[i][j]) % MOD;
            state_freq[i+1][j-1] = (state_freq[i+1][j-1] + state_freq[i][j]) % MOD;
        }
    }
    for i in 0..=k {
        for x in 1..=n {
            freq[x] = (freq[x] + state_freq[i][x] * state_freq[k - i][x]) % MOD;
        }
    }
    freq
}

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let (n, k, q): (usize, usize, usize) = (sc.next(), sc.next(), sc.next());
    let mut arr: Vec<i64> = (0..n).map(|_| sc.next()).collect();
    let freq: Vec<i64> = generate_freq(n, k);
    let mut ans: i64 = 0;
    for i in 1..=n {
        ans = (ans + freq[i] * arr[i-1]) % MOD;
    }
    for _ in 0..q {
        let (i, x): (usize, i64) = (sc.next(), sc.next());
        ans = (ans + ((x - arr[i-1]) * freq[i]) % MOD + MOD) % MOD;
        arr[i-1] = x;
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
