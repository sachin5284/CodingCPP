function Evaluate(a,b,showOk,showError)
{
    let result = a%b;
    if(result===0)
    {
        showOk();
    }
    else 
        showError();
}

function showOk()
{
    console.log("Ok!!")
}

function showError()
{
    console.error("Error occured Try Again !!")
}
let func = (s)=>console.log('sachin ${s}');
Evaluate(10,5,showOk,showError);
func("kumar");