use std::i64;

fn inside(l: &i64, r: &i64, x: &i64) -> bool {
    (l - x).abs() + (x - r).abs() == (l - r).abs()
}

fn maybe_reach(l: &i64, x: &i64, t: &i64, nt: &i64) -> bool {
    (l - x).abs() <= (nt - t).abs()
}

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let n: usize = sc.next();
        let mut instruction: Vec<(i64, i64)> = (0..n).map(|_| (sc.next(), sc.next())).collect();
        instruction.push((i64::MAX, i64::MAX));
        let mut ans: usize = 0;
        let mut lim: i64 = 0;
        let (mut l, mut r) = (0 as i64, 0 as i64);
        for i in 0..n {
            let (t, x) = instruction[i].clone();
            let (nt, _) = instruction[i+1].clone();
            if t >= lim {
                lim = t + (r - x).abs();
                l = r;
                r = x;
            }
            ans += if inside(&l, &r, &x) && maybe_reach(&l, &x, &t, &nt) {1} else {0};
            l += (nt - t) * (if r - l >= 0 {1} else {-1});
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
