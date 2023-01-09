
class ExampleClass {
    val scope = CoroutineScope(Job() + Dispatchers.Main)

    fun exampleMethod() {
        scope.launch {

        }
    }

    fun cleanUp() {
        scope.cancle()
    }
}


fun main() {
    val ex:ExampleClass = ExampleClass()
    ex.exampleMethod()
}
