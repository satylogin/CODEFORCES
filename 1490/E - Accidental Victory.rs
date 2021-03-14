use std::io::{self, Write};

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let n: usize = sc.next();
        let mut entry: Vec<(i64, usize)> = (1..=n).map(|i| (sc.next(), i)).collect();
        entry.sort();
        let (mut start, mut end, mut ans): (i32, i32, i64) = (0, n as i32 - 1, entry[n-1].0);
        while start <= end {
            let mid = (start + end) >> 1;
            let mut can_win = true;
            let mut cur_score = entry[mid as usize].0;
            for i in 0..n {
                if i == mid as usize {
                    continue;
                }
                if cur_score < entry[i].0 {
                    can_win = false;
                    break;
                }
                cur_score += entry[i].0;
            }
            if can_win {
                ans = entry[mid as usize].0;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        let mut winners: Vec<usize> = vec![];
        for i in 0..n {
            if entry[i].0 >= ans {
                winners.push(entry[i].1);
            }
        }
        winners.sort();
        writeln!(out, "{}", winners.len()).unwrap();
        winners.into_iter().for_each(|x| write!(out, "{} ", x).unwrap());
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
