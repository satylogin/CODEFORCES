use std::io::{self, Write};
use std::collections::BTreeMap;
use std::cmp::min;

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let n: i32 = sc.next();
        
        let mut freq: BTreeMap<i32, i32> = BTreeMap::new();
        (0..n).for_each(|_| *freq.entry(sc.next()).or_insert(0) += 1);
        let freq_cnt: Vec<i32> = freq.values().cloned().collect();
        
        let mut freq: BTreeMap<i32, i32> = BTreeMap::new();
        freq_cnt.into_iter().for_each(|x| *freq.entry(x).or_insert(0) += 1);
        
        let mut left: i32 = n;
        let mut ans: i32 = n;
        let mut offset: i32 = 0;
        
        for f in (1..=n).rev() {
            if freq.contains_key(&f) {
                let v: i32 = freq.get(&f).unwrap().clone();
                left -= f * v;
                ans = min(ans, left + offset);
                offset += v;
                left += v * (f - 1);
                *freq.entry(f-1).or_insert(0) += v;
            }
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
