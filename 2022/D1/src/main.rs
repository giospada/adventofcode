use std::fs;

const FILE_INPUT: &str = "input.txt";

type Input = Vec<Vec<i32>>;

fn inputReading() -> Input {
    let mut lines = fs::read_to_string(FILE_INPUT).expect("impossibile aprire  il file ");

    let lines: Vec<&str> = lines.lines().into_iter().collect();

    let mut arr: Vec<Vec<i32>> = vec![];
    let mut current = vec![];
    for line in lines {
        if line.is_empty() {
            arr.push(current);
            current = vec![];
        } else {
            current.push(line.parse().unwrap());
        }
    }
    arr.push(current);
    arr
}

fn fstar(input: Input) -> i32 {
        input.into_iter()
            .map(|a| a.into_iter().sum::<i32>())
            .into_iter()
            .max()
            .unwrap()
}
fn sstar(input: Input) -> i32 {
        let mut arr:Vec<i32>=input.into_iter()
            .map(|a| a.into_iter().sum::<i32>()).collect();
        arr.sort();
        let mut sum = 0;
        for i in 1..4 {
            sum = sum + arr[arr.len()-i];   
        }
        sum 
}

fn main() {
    let input = inputReading();
    println!("first star:{}",fstar(input.clone()));
    println!("second start : {} \n",sstar(input.clone()));
}
