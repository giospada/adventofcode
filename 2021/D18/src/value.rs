use crate::pair::Pair;

pub enum Value{
    Number(i32),
    Pair(Box<Pair>)
}
impl Value {

    pub fn from_str(string:&str) -> Result<(Value,usize),&str>{
        if string.starts_with("[") {
            let (l,index) = Pair::from_str(&string)?;
            return Ok((Value::Pair(Box::new(l)),index));
        }
        let end=len_number(string)?;

        let value = string[..end].parse::<i32>().unwrap();

        Ok((Value::Number(value),end))
    }

    pub fn magnitude(&self) -> i64 {
        match self {
           Value::Number(l)  => {
            *l as i64
           }
           Value::Pair(pair) =>{
                pair.magnitude()
           }
        }
    }
}
impl ToString for Value {
    fn to_string(&self) -> String {
        match self {
            Value::Number(number) => {
                number.to_string()
            },
            Value::Pair(pair) => {
               pair.to_string() 
            }
        }
    }
}

impl Clone for Value {

    fn clone(&self) -> Self {
        match &self {
            Value::Number(number) => {
                Value::Number(*number)
            },
            Value::Pair(pair) => {
                Value::Pair(pair.clone())
            }
        }
    }

    fn clone_from(&mut self, source: &Self) { 
        *self = source.clone();
    }
}


fn len_number(string:&str) -> Result<usize,&str>{
    let mut end = 0;
    for char in string.chars(){
        if !(char >= '0' && char <= '9'){
            break;
        }
        end += 1;
    }
    if end == 0 {
        return Err("non ci sono numeri");
    }
    Ok(end)
}