use std::collections::btree_set::BTreeSet;
use std::io;
use std::io::Write;
use std::i64::MAX;
use std::cmp::min;

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let mut k: i64 = sc.next();
    let l: i64 = sc.next();
    let r: i64 = sc.next();
    let t: i64 = sc.next();
    let x: i64 = sc.next();
    let y: i64 = sc.next();
    let mut d = 0;
    if y < x {
        if k + y > r {
            d = min((k + y - r + x - 1) / x, (k - l) / x);
            k -= d * x;
        }
        if k + y <= r {
            d += (k - l) / (x - y);
        }
    } else {
        let mut states: BTreeSet<i64> = BTreeSet::new();
        if k >= l + x {
            d = (k - l) / x;
            k -= d * x;
        }
        states.insert(k);
        while k + y <= r {
            k = k + y;
            let m = (k - l) / x;
            k -= m * x;
            d += m;
            if states.contains(&k) {
                d = MAX;
                break;
            }
        }
    }
    writeln!(out, "{}", if d >= t {"Yes"} else {"No"}).unwrap();
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
