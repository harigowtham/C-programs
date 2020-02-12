function add(x){
    let sum = x;
    function resultFn(y){
        sum *= y;
        return resultFn;
    }
    resultFn.valueOf = function(){
            return sum;
        };
    return resultFn;
}
console.log(add(2)(3)(4).valueOf())
