use std::cmp::max;

fn get_max(bags: &Vec<Vec<i64>>, index: Vec<usize>) -> i64 {
    let s1: i64 = bags[index[0]].iter().sum();
    let s2: i64 = bags[index[1]][1..].iter().sum();
    let s3: i64 = bags[index[2]][1..].iter().sum();
    max(
        s1 + s2 + s3 - bags[index[1]][0] - bags[index[2]][0],
        s1 + s2 - s3 + bags[index[1]][0] - bags[index[2]][0]
    )
}

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let n: Vec<usize> = (0..3).map(|_| sc.next()).collect();
    let mut bags: Vec<Vec<i64>> = (0..3).map(|i| (0..n[i]).map(|_| sc.next()).collect()).collect();
    (0..3).for_each(|i| bags[i].sort());
    let ans = vec![
        get_max(&bags, vec![0, 1, 2]),
        get_max(&bags, vec![0, 2, 1]),
        get_max(&bags, vec![1, 0, 2]),
        get_max(&bags, vec![1, 2, 0]),
        get_max(&bags, vec![2, 0, 1]),
        get_max(&bags, vec![2, 1, 0])
    ].iter().max().unwrap().clone();

    writeln!(out, "{}", ans).unwrap();
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
