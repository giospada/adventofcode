use std::fs;

use itertools::Itertools;

const FILE_INPUT: &str = "input.txt";

type Input = Vec<[Vec<i32>; 2]>;
type Input2 = Vec<Vec<i32>>;

fn inputReading() -> Input {
    let lines = fs::read_to_string(FILE_INPUT).expect("impossibile aprire  il file ");

    let lines: Vec<&str> = lines.lines().into_iter().collect();

    let to_val = |x: &char| {
        let xval = *x as i32;
        if *x >= 'a' && *x <= 'z' {
            1 + xval - ('a' as i32)
        } else {
            27 + xval - ('A' as i32)
        }
    };

    lines
        .into_iter()
        .map(|x| {
            let mut t = [Vec::new(), Vec::new()];
            let chars: Vec<char> = x.chars().collect();
            for (i, c) in chars.iter().enumerate() {
                if i < chars.len() / 2 {
                    t[0].push(to_val(c));
                } else {
                    t[1].push(to_val(c));
                }
            }
            t
        })
        .collect()
}
fn inputReading2() -> Input2 {
    let lines = fs::read_to_string(FILE_INPUT).expect("impossibile aprire  il file ");

    let lines: Vec<&str> = lines.lines().into_iter().collect();

    let to_val = |x: char| {
        let xval = x as i32;
        if x >= 'a' && x <= 'z' {
            1 + xval - ('a' as i32)
        } else {
            27 + xval - ('A' as i32)
        }
    };

    lines
        .into_iter()
        .map(|x| x.chars().map(|c| to_val(c)).collect())
        .collect()
}

fn fstar(input: Input) -> i32 {
    use std::collections::BTreeSet;
    input
        .iter()
        .map(|x| {
            let mut set = BTreeSet::new();
            x[0].iter().for_each(|x| {
                set.insert(x);
            });

            let mut sum = 0;
            x[1].iter().for_each(|x| {
                if set.contains(x) {
                    sum = sum + x;
                    set.remove(x);
                }
            });
            sum
        })
        .sum()
}
fn sstar(input: Input2) -> i32 {
    use std::collections::BTreeSet;
    input
        .into_iter()
        .chunks(3)
        .into_iter()
        .map(|x| {
            x.into_iter()
                .map(|x| x.into_iter().collect::<BTreeSet<i32>>())
                .into_iter()
                .reduce(|acc, x| acc.intersection(&x).cloned().collect())
                .unwrap()
                .into_iter()
                .next()
                .unwrap()
        })
        .sum()
}

fn main() {
    println!("first star:{}", fstar(inputReading()));
    println!("second start : {} \n", sstar(inputReading2()));
}
