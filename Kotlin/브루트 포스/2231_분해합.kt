/* BOJ - 2231 분해합 */

package boj

const val NON_EXISTENT = 0

fun digitSum(number: Int) = with(number.toString()) {
    var sum = 0
    this.forEach { sum += (it - '0') }
    sum
}

fun findConstructor(number: Int): Int {
    for (constructor in 1..number) {
        val decompositionSum = constructor + digitSum(constructor)
        if (number == decompositionSum) {
            return constructor
        }
    }
    return NON_EXISTENT
}

fun main() {
    val number = readLine()?.toInt() ?: 0
    println(findConstructor(number))
}