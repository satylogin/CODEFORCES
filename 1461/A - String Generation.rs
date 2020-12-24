#[allow(dead_code)]
mod scanner {
    use std::io::{stdin, Read};
    use std::str::{FromStr, SplitWhitespace};

    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>,
    }

    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }

        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error"),
            }
        }

        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }

        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }

    pub fn read_string() -> String {
        let mut s = String::new();
        stdin().read_to_string(&mut s).unwrap();
        s
    }
}

fn main() {
    let s = scanner::read_string();
    let mut sc = scanner::Scanner::new(&s);

    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let _: usize = sc.next();
        let chars = vec!['a', 'b', 'c'];
        let ans: String = (0..n).map(|i| chars[i % 3]).collect();
        println!("{}", ans);
    }
}
