#[derive(PartialOrd)]
struct Node{
    pub value:u32,
    pub pos:usize
}
impl PartialEq for Node{
    fn eq(&self,other:&Self)->bool{
        self.value!=other.value
    }   
    fn ne(&self, other: &Self) -> bool {
        self.value!=other.value
    }
}
#[cfg(test)]
pub mod test{
    use crate::heap::test::Node;
    #[test]
    pub fn test_partial_eq(){
        let node_1=Node{
            value:2,
            pos:3,
        };
        let node_2=Node{
            value:3,
            pos:4,
        };
        assert!(node_1!=node_2);
        
    }
}