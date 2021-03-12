use std::collections::BTreeSet;
use std::cmp::Ordering;

fn main() {
    use std::io::{self, Write};
 
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());


    let n: usize = sc.next();
    let queries: Vec<i64> = (0..n).map(|_| sc.next()).collect();
    let mut set: BTreeSet<i64> = BTreeSet::new();
    let mut a: i64 = 2;
    while (a * a - 1) / 2 < 1e9 as i64 {
        let b = (a * a - 1) / 2;
        let c = b + 1;
        if a <= b && b <= c && ((a * a + b * b) == (c * c)) && (c == (a * a - b)) {
            set.insert(c);
        }
        a += 1;
    }
    let ns: Vec<i64> = set.into_iter().collect();
    for query in queries {
        let lower = ns.binary_search_by(|x| {
            if *x <= query {Ordering::Less} else {Ordering::Greater}
        }).err().unwrap();
        writeln!(out, "{}", lower).unwrap();
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
