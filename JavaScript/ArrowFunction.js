let group = {
    title:"Our Group",
    students: ["John","Pete","Alice"],
    showList(){
        this.students.forEach
        (student => console.log(this.title+ ' : '+ student));
    }
};

group.showList();
let descriptor = Object.getOwnPropertyDescriptor(group,"title");
console.log(descriptor);