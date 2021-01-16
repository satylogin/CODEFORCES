use std::cmp::min;

fn check(i: usize, arr: &Vec<usize>) -> bool {
    (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) || (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
}

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let n: usize = sc.next();
        let mut arr: Vec<usize> = (0..n).map(|_| sc.next()).collect();
        let cur: usize = (1..n - 1).map(|i| check(i, &arr) as usize).sum();
        let mut ans: usize = cur.clone();
        for i in 1..n - 1 {
            let tmp: usize = arr[i];
            let mut here = cur.clone();
            here -= (i - 1 > 0 && check(i - 1, &arr)) as usize;
            here -= (i + 1 < n - 1 && check(i + 1, &arr)) as usize;
            here -= check(i, &arr) as usize;
            arr[i] = arr[i - 1].clone();
            ans = min(
                ans,
                here + (i - 1 > 0 && check(i - 1, &arr)) as usize
                    + (i + 1 < n - 1 && check(i + 1, &arr)) as usize,
            );
            arr[i] = arr[i + 1].clone();
            ans = min(
                ans,
                here + (i - 1 > 0 && check(i - 1, &arr)) as usize
                    + (i + 1 < n - 1 && check(i + 1, &arr)) as usize,
            );
            arr[i] = tmp;
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
