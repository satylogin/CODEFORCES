fn main() {
    use std::io;
    use std::io::Write;

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut array: Vec<i32> = (0..n).map(|_| sc.next()).collect();
        let mut sum: Vec<i64> = vec![0; 2];
        for (i, x) in array.iter().enumerate() {
            sum[i&1] += *x as i64;
        }
        let idx: usize = if sum[0] < sum[1] {0} else {1};
        for (i, x) in array.iter_mut().enumerate() {
            if i & 1 == idx {
                *x = 1;
            }
        }
        array.iter().for_each(|x| write!(out, "{} ", x).unwrap());
        writeln!(out, "").unwrap();
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
