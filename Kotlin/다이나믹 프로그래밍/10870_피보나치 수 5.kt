/* BOJ - 10870 피보나치 수 5 */

package boj

const val MEMORY_SIZE = 21
const val UNKNOWN_NUMBER = -1

val memory = Array<Int>(MEMORY_SIZE) { number -> if (number < 2) number else UNKNOWN_NUMBER }

fun fibonacci(number: Int): Int {
    if (memory[number] == UNKNOWN_NUMBER) {
        memory[number] = fibonacci(number - 1) + fibonacci(number - 2)
    }
    return memory[number]
}

fun main() {
    val n = readLine()?.toInt() ?: 0
    println(fibonacci(n))
}