use std::cmp::max;

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    const N: usize = 200000;
    let tc: usize = sc.next();
    for _ in 0..tc {
        let n: usize = sc.next();
        let mut freq: Vec<usize> = vec![0; N + 1];
        (0..n).for_each(|_| freq[sc.next::<usize>()] += 1);
        let mut ans: Vec<usize> = vec![0; N + 1];
        for i in 1..=N {
            ans[i] += freq[i];
            for j in (i + i..=N).step_by(i) {
                ans[j] = max(ans[j], ans[i]);
            }
        }
        writeln!(out, "{}", n - ans.iter().max().unwrap()).unwrap();
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
