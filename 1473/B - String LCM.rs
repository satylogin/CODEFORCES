use std::mem::swap;

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let mut a: Vec<char> = sc.next::<String>().chars().collect();
        let mut b: Vec<char> = sc.next::<String>().chars().collect();
        if a.len() < b.len() {
            swap(&mut a, &mut b);
        }
        let mut i: usize = 0;
        let mut j: usize = 0;
        let mut s: Vec<char> = vec![];
        let mut valid: bool = true;
        for _ in 0..b.len() {
            s.append(&mut a.clone());
            while i < s.len() {
                if s[i] != b[j] {
                    break;
                }
                i += 1;
                j = (j + 1) % b.len();
            }
            if i != s.len() {
                valid = false;
                break;
            }
            if j == 0 {
                break;
            }
        }
        let mut ans = String::from("-1");
        if valid {
            ans = s.into_iter().collect::<String>();
        }
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
