/* BOJ - 9498 시험 성적 */

package boj

fun main() {
    val grade: Char = when (readLine()?.toInt() ?: 0) {
        in 90..100 -> 'A'
        in 80..89 -> 'B'
        in 70..79 -> 'C'
        in 60..69 -> 'D'
        else -> 'F'
    }
    println(grade)
}