var productsList=[];
function fill(){
    console.log("Fill is called.");
    productsList = [{
        name : 'First',
        Description: "Some info",
        price : 100,
    },
    {
        name : 'Second',
        Description: "Some more info",
        price : 200,
    }]  
    content();
}

function content(){
    console.log("Content is called.");
    document.getElementById("menu").innerHTML=`
    <table>
            <thead>
                <tr>
                    <th>Sr no.</th>
                    <th>Product name</th>
                    <th>Description</th>
                    <th>Price</th>
                </tr>
            </thead>
            <tbody>
                ${usingMap()}
            </tbody>
        </table>
        <h3>List of products</h3>
    `

}

function usingMap(){
    if(productsList.length == 0) return "Loading data";
    var temp = productsList.map((item, i) =>{
        return `<tr>
        <td>${i+1}</td>
        <td>${item.name}</td>
        <td>${item.Description}</td>
        <td>${item.price}</td>
        </tr>`
    })
    return temp.join("");
    //If we don't do join, then a comma will appear since map uses comma by defualt
}
// fill();
setTimeout(fill , 5000);
content();

// function getProductList(){
    //     var rows = "";
    //     for(let i = 1; i <= productsList.length; i++){
        //         rows = rows + `
        //                     <tr>
        //                     <td>${i}</td>
        //                     <td>${productsList[i - 1].name}</td>
        //                     <td>${productsList[i - 1].Description}</td>
        //                     <td>${productsList[i - 1].price}</td>
//                     </tr>`
//     }
//     return rows;
// }