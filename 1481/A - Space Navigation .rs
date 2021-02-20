use std::collections::btree_map::BTreeMap;

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let (a, b): (i32, i32) = (sc.next(), sc.next());
        let mut freq: BTreeMap<char, i32> = BTreeMap::new();
        for m in  sc.next::<String>().chars() {
            *freq.entry(m).or_insert(0) += 1;
        }
        let valid = (*freq.get(&(if a > 0 {'R'} else {'L'})).unwrap_or(&0) >= a.abs()) &&
            (*freq.get(&(if b > 0 {'U'} else {'D'})).unwrap_or(&0) >= b.abs());
        writeln!(out, "{}", if valid {"YES"} else {"NO"}).unwrap();
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
