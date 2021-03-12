/* BOJ - 3009 네 번째 점 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

data class Point(val x: Int, val y: Int)

fun findFourthPoint(points: MutableList<Point>) = run {
    val x = when (points[0].x) {
        points[1].x -> points[2].x
        points[2].x -> points[1].x
        else -> points[0].x
    }
    val y = when (points[0].y) {
        points[1].y -> points[2].y
        points[2].y -> points[1].y
        else -> points[0].y
    }
    Point(x, y)
}

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))
    val points = mutableListOf<Point>()

    repeat(3) {
        StringTokenizer(reader.readLine()).let { token ->
            val x = token.nextToken().toInt()
            val y = token.nextToken().toInt()
            points.add(Point(x, y))
        }
    }
    findFourthPoint(points).apply { writer.write("${this.x} ${this.y}") }
    writer.close()
}