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
        let m: usize = sc.next();
        let array: Vec<i32> = sc.next_vec(n);
        let mut greatest_invalid: usize = n+1;
        for (i, x) in array.iter().enumerate() {
            if i+1 != *x as usize {
                greatest_invalid = i + 1;
            }
        }
        let mut prob: Vec<f64> = vec![1.0; n+1];
        for _ in 0..m {
            let x: usize = sc.next();
            let p: f64 = sc.next();
            prob[x] *= 1.0 - p;
        }
        let mut p: f64 = 1.0;
        if greatest_invalid != n + 1 {
            p = 1.0 - prob[greatest_invalid..n+1].iter().fold(1.0, |acc, x| acc * x);
        }
        println!("{:.10}", p);
    }
}
