fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let (n, m): (usize, usize) = (sc.next(), sc.next());
        let edges: Vec<Vec<char>> = (0..n).map(|_| sc.next::<String>().chars().collect()).collect();
        let (mut x, mut y, mut z) = (0, 0, 0);
        for i in 0..n {
            for j in 0..n {
                if i != j && edges[i][j] == edges[j][i] { x = i + 1; y = j + 1; }
            }
        }
        if m & 1 == 1 { x = 1; y = 2; }
        if x != 0 {
            writeln!(out, "YES").unwrap();
            (0..=m).for_each(|i| write!(out, "{} ", if i & 1 == 0 {x} else {y}).unwrap());
            writeln!(out).unwrap();
        } else {
            for i in 0..n {
                let (mut a, mut b) = (0, 0);
                for j in 0..n {
                    if edges[i][j] == 'a' { b = j + 1; }
                    if edges[j][i] == 'a' { a = j + 1; }
                }
                if a != 0 && b != 0 { x = a; y = i + 1; z = b; break; }
            }
            let mut ans: Vec<usize> = vec![];
            (0..(m / 2)).for_each(|_| ans.append(&mut vec![x, y, z, y]));
            if x == 0 {
                writeln!(out, "NO").unwrap();
            } else {
                let offset = if m % 4 == 0 {1} else {0};
                writeln!(out, "YES").unwrap();
                (0..=m).for_each(|i| write!(out, "{} ", ans[i + offset]).unwrap());
                writeln!(out).unwrap();
            }
        }
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
