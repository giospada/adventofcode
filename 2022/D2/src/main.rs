use std::{
    collections::{BTreeMap, BTreeSet},
    fs,
};

const FILE_INPUT: &str = "input.txt";

type Input = Vec<(char, char)>;

fn inputReading() -> Input {
    let mut lines = fs::read_to_string(FILE_INPUT).expect("impossibile aprire  il file ");

    let lines: Vec<&str> = lines.lines().into_iter().collect();
    lines
        .into_iter()
        .map(|x| {
            let mut ar = x.split(" ");
            let (fc, sc) = (
                ar.next().expect("prima lettera non letta"),
                ar.next().expect("second lettera non letta"),
                );
            (fc.chars().nth(0).unwrap(), sc.chars().nth(0).unwrap())
        })
    .collect()
}


fn fstar(input: Input) -> i32 {
    let state_val: BTreeMap<char, i32> = BTreeMap::from([('X', 1), ('Y', 2), ('Z', 3)]);
    let winning_state: BTreeSet<(char, char)> =
        BTreeSet::from([('C', 'X'), ('A', 'Y'), ('B', 'Z')]);
    let drow_state: BTreeSet<(char, char)> = BTreeSet::from([('A', 'X'), ('B', 'Y'), ('C', 'Z')]);
    input
        .into_iter()
        .map(|x| {
            *state_val.get(&x.1).unwrap_or(&0)
                + if winning_state.contains(&x) { 6 } else { 0 }
            + if drow_state.contains(&x) { 3 } else { 0 }
        })
    .sum()
}
fn sstar(input: Input) -> i32 {

    let winning_state= 
        BTreeMap::from([('C', 'X'), ('A', 'Y'), ('B', 'Z')]);
    let drow_state = BTreeMap::from([('A', 'X'), ('B', 'Y'), ('C', 'Z')]);
    let losing_state = BTreeMap::from([('B', 'X'), ('C', 'Y'), ('A', 'Z')]);

    let state_val  = BTreeMap::from([('X', losing_state), ('Y', drow_state), ('Z', winning_state)]);

    let first_star_input=input
        .into_iter()
        .map(|x| {
            let second_char=*state_val.get(&x.1).expect("state not found").get(&x.0).expect("char not found");

            (x.0,second_char)
        }).collect();
    fstar(first_star_input)
}

fn main() {
    let input = inputReading();
    println!("first star: {}", fstar(input.clone()));
    println!("second start : {}", sstar(input));
}
