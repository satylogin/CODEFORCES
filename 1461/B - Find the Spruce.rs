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
        let pattern: Vec<String> = (0..n).map(|_| sc.next::<String>()).collect();
        let mut pref_sum: Vec<Vec<usize>> = vec![vec![0; m+1]; n+1];
        for i in 1..n+1 {
            for (j, c) in pattern[i-1].chars().enumerate() {
                pref_sum[i][j+1] = pref_sum[i][j] + if c == '*' {1} else {0};
            }
        }
        let mut ans = 0;
        for i in 1..n+1 {
            for j in 1..m+1 {
                for k in 1..501 {
                    if i + k - 1 <= n &&
                        j + k - 1 <= m &&
                        j >= k &&
                        pref_sum[i + k - 1][j + k - 1] - pref_sum[i + k - 1][j - k] == 2 * k - 1 {
                        ans += 1;
                    } else {
                        break;
                    }
                }
            }
        }
        println!("{}", ans);
    }
}
