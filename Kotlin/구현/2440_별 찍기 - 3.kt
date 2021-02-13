/* BOJ - 2440 별 찍기 - 3 */

package boj

fun main() {
    val stringBuilder = StringBuilder()
    for (numberOfStars in readLine()!!.toInt() downTo 1) {
        val stars = "*".repeat(numberOfStars)
        stringBuilder.append("$stars\n")
    }
    print(stringBuilder)
}