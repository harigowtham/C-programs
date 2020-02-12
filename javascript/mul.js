/*
 * Object Constructor
 */
var foo = function(x) {
    this.x = x;
};

/*
 * Object Protoype
 */
foo.prototype = {
    /*
     * f is the name that is going to be used to call the various overloaded versions
     */
    f: function() {

        /*
         * Save 'this' in order to use it inside the overloaded functions
         * because there 'this' has a different meaning.
         */
        var that = this;

        /*
         * Define three overloaded functions
         */
        var f1 = function(arg1) {
            console.log("f1 called with " + arg1);
            return arg1*that.x;
        }

        var f2 = function(arg1, arg2) {
             console.log("f2 called with " + arg1 + " and " + arg2);
             return arg1*arg2*that.x;
        }

        var f3 = function(arg1) {
             console.log("f3 called with [" + arg1[0] + ", " + arg1[1] + "]");
             return arg1[0] * arg1[1];
        }

        /*
         * Use the arguments array-like object to decide which function to execute when calling f(...)
         */
        if (arguments.length === 1 && !Array.isArray(arguments[0])) {
            return f1(arguments[0]);
        } else if (arguments.length === 2) {
            return f2(arguments[0], arguments[1]);
        } else if (arguments.length === 1 && Array.isArray(arguments[0])) {
            return f3(arguments[0]);
        }
    }
}

/*
 * Instantiate an object
 */
var obj = new foo("z");

/*
 * Call the overloaded functions using f(...)
 */
console.log(obj.f(1));         // executes f1, returns "xz"
console.log(obj.f(3, 2));    // executes f2, returns "xyz"
console.log(obj.f([2, 4]));
