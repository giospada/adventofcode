use std::fs;

const SCORE_LIMIT:i32 = 1000;
const BOARD_LIMIT:i32 = 10;
const LANCI_CONSECUTIVI:i32 = 3;
const INPUT:&str = "input";


struct ModIterator{
    modulo:i32,
    current:i32,
    start:i32,
    consecutivi:i32,
}

impl ModIterator {
    fn new() -> Self{
        Self { modulo:1000,start:1,current:0, consecutivi:0}
    }

    fn sum_dice(&mut self) ->i32{
        (0..LANCI_CONSECUTIVI).into_iter().map(|_| self.next()).sum()
    }

    fn next(&mut self) -> i32 {
        if self.current == self.modulo {
            self.current = self.start;
        }else {
            self.current = self.current + 1;
        }
        self.current
    }

}


struct Player{
    currentPos:i32,
    score:i32
}

impl Player {
    fn from_pos(pos:i32) -> Self{
        Self { currentPos:pos, score:0 } 
    }

    fn new() -> Self{
        Self { currentPos:0, score:0 } 
    }

    fn muovi(&mut self, passi:i32){
        self.currentPos = ((self.currentPos -1 + passi) % BOARD_LIMIT )+1;
        self.score += self.currentPos;
    }

    fn finish(&self) -> bool {
        self.score >= SCORE_LIMIT
    }
}



fn main() {

    let mut rounds = 0;
    let mut players = [Player::from_pos(3),Player::from_pos(7)];
    let mut currentPlayer = 0;
    let mut iter = ModIterator::new();
    while !(players[0].finish() || players[1].finish()) {

        players[currentPlayer].muovi(iter.sum_dice());

        currentPlayer = 1- currentPlayer;
        rounds+=LANCI_CONSECUTIVI;
    }
    let min_score = std::cmp::min(players[0].score,players[1].score);
    print!("{} {} {}",min_score,rounds,min_score*rounds)
}
