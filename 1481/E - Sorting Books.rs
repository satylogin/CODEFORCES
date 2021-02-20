use std::cmp::{min, max};

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let n: usize = sc.next();
    let array: Vec<usize> = (0..n).map(|_| sc.next()).collect();
    let mut first: Vec<usize> = vec![usize::MAX; n + 1];
    let mut last: Vec<usize> = vec![0; n + 1];
    let mut freq: Vec<usize> = vec![0; n + 1];
    let mut dp: Vec<usize> = vec![0; n + 1];
    let mut mem: Vec<usize> = vec![0; n + 1];
    let mut max_ended: usize = 0;
    for i in 0..n {
        first[array[i]] = min(first[array[i]], i);
        last[array[i]] = max(last[array[i]], i);
    }
    let mut ans: usize = 0;
    for i in 0..n {
        if first[array[i]] == i {
            dp[array[i]] += max_ended;
        }
        dp[array[i]] += 1;
        if last[array[i]] == i {
            max_ended = max(max_ended, dp[array[i]]);
            mem[i] = dp[array[i]];
        }
    }
    let mut m_freq = 0;
    for i in (0..n).rev() {
        ans = max(ans, mem[i] + m_freq);
        freq[array[i]] += 1;
        m_freq = max(m_freq, freq[array[i]]);
    }
    writeln!(out, "{}", n - ans).unwrap();
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
