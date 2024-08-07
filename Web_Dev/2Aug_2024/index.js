function renderProducts(){
    var productsListFromServer;

    function getProductList(){
        console.log("fetching product list")
        if(productsList)  productsListFromServer = productsList;
        initProductListTable();
    }

    
    //yaha pr hm ek list bana lenge aur jo hmne itna saara table banaya hua hai uski bajaye ye list use krenge.
    
    //ye hamne pehle kiya hua tha normally table banake html se. 
    function initProductListTable(){
        console.log("initializing product list")
        if(productsListFromServer === undefined || productsListFromServer?.length === 0){
            console.log("Yes it is undefined.");
            document.getElementById("productMenu").innerHTML = getLoader()
            return;
        }
        document.getElementById("productMenu").innerHTML = `
            <h3>List of Products</h3>
            <table>
                <thead>
                    <tr>
                        <th>Sr. No.</th>
                        <th>Product Name</th>
                        <th>Description</th>
                        <th>Price</th>
                    </tr>
                </thead>
                <tbody>
                    ${getProductListHTMLusingMap()}
                </tbody>
            </table>
            `
    }
    
    // init()
    
    //normally for loop lagake
    function getProductListHTML(){
        var rows = ""
        for(let i = 0; i < productsListFromServer?.length; i++){
            rows = rows +
            `<tr>
            <td>${i + 1}</td>
            <td>${productsListFromServer[i].name}</td>
            <td>${productsListFromServer[i].description}</td>
            <td>${productsListFromServer[i].price}</td>
            </tr>`
        }
        return rows;
    }
    
    function getLoader(){
        if(productsListFromServer === undefined || productsListFromServer?.length === 0) {
            console.log("Ran undefined part of getLoader.");
            return `<div>Loading data</div>`
        }
    }
    //map callback etc 
    function getProductListHTMLusingMap(){
    
        // if(productsListFromServer === undefined || productsListFromServer?.length === 0) {
        //     return <div>Loading data</div>
        // }
    
        var rowsOfProducts = productsListFromServer?.map((item, i) => {
            return `<tr>
            <td>${i + 1}</td>
            <td>${item.name}</td>
            <td>${item.description}</td>
            <td>${item.price}</td>
            </tr>`
        })
        return rowsOfProducts?.join("");
    }
    initProductListTable();
    setTimeout(getProductList, 2000);
    // getProductList();
    // var productsListFromServer = [];
    // init()
}

renderProducts();