use std::io::{self, Write};
use std::cmp::max;

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let (n, q): (usize, usize) = (sc.next(), sc.next());
        let arr: Vec<i64> = (0..n).map(|_| sc.next()).collect();
        
        let mut pref_sum: Vec<i64> = arr.clone();
        (1..n).for_each(|i| pref_sum[i] += pref_sum[i-1]);

        let mut max_arr: Vec<i64> = pref_sum.clone();
        (1..n).for_each(|i| max_arr[i] = max(max_arr[i], max_arr[i-1]));

        let mx: i64 = *pref_sum.iter().max().unwrap();
        let sum: i64 = pref_sum[n-1];
        
        for _ in 0..q {
            let mut x: i64 = sc.next();
            let mut ans: i64 = 0;
            if mx < x {
                if sum <= 0 {
                    write!(out, "-1 ").unwrap();
                    continue;
                }
                let times = (x - mx + sum - 1) / sum;
                ans += times * n as i64;
                x -= times * sum;
            }
            let (mut start, mut end, mut idx): (i32, i32, i32) = (0, n as i32 - 1, 0);
            while start <= end {
                let mid: i32 = (start + end) >> 1;
                if max_arr[mid as usize] >= x {
                    idx = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            ans += idx as i64;
            write!(out, "{} ", ans).unwrap();
        }
        writeln!(out).unwrap();
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
