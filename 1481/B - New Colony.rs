fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let (n, mut k): (usize, usize) = (sc.next(), sc.next());
        let mut height: Vec<usize> = (0..n).map(|_| sc.next()).collect();
        let mut last_update: usize = 0;
        let mut updated = true;
        while k > 0 && updated {
            updated = false;
            for i in 0..n-1 {
                if height[i] < height[i+1] {
                    height[i] += 1;
                    k -= 1;
                    last_update = i + 1;
                    updated = true;
                    break;
                }
            }
        }
        writeln!(out, "{}", if k > 0 {-1} else {last_update as i32}).unwrap();
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
