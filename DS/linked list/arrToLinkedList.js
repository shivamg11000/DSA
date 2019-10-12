// node of a linked list
class Node{
    constructor(info){
        this.link = null;
        this.info = info;
    }
    getInfo(){
        return this.info;
    }
    getLink(){
        return this.link;
    }
    setLink(link){
        this.link = link;
    }
}
// given root/head element, it inserts new node at the end of a linked list
const insert = function(root, item){
    const temp = new Node(item);
    let current;

    if(root==null)
        root=temp;
    else{
        current = root;
        while(current.getLink()!=null) {
            current = current.link;
        }
        current.setLink(temp);
    }    
    return root;
}

// prints linked list start from root
const display = function(root){
    let current = root;
    while(current!=null){
        console.log(current.getInfo());
        current = current.link;
    }
}

// arr -> Linked List
const arrToList = function(arr){
    let root = null;
    for(let i=0 ; i<arr.length ; i++)
        root = insert(root, arr[i]);   
    return root;     
}

const arr = [1,2,3,4,5,6,7,8,9];
const root = arrToList(arr);

display(root);
