use std::cmp::max;

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let n: i32 = sc.next();
        let array: Vec<i32> = (0..n).map(|_| sc.next()).collect();
        let mut unused: Vec<i32> = vec![];
        for i in 1..2 * n + 1 {
            if array.binary_search(&i).is_err() {
                unused.push(i);
            }
        }
        let mut last_mapped: i32 = n;
        let mut to_mach: i32 = n - 1;
        for i in (0..n).rev() {
            while to_mach >= 0 {
                if array[i as usize] > unused[to_mach as usize] {
                    last_mapped = i;
                }
                to_mach -= 1;
                if last_mapped == i {
                    break;
                }
            }
        }
        let mut first_mapped: i32 = -1;
        let mut to_mach: i32 = 0;
        for i in 0..n {
            while to_mach < n {
                if array[i as usize] < unused[to_mach as usize] {
                    first_mapped = i;
                }
                to_mach += 1;
                if first_mapped == i {
                    break;
                }
            }
        }
        writeln!(out, "{}", max(first_mapped + 1 - last_mapped + 1, 0)).unwrap();
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
