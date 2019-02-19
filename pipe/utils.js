var angle = .1;
var force_scale = 1.0;
var color_names = ["black", "red", "blue"];
var Module = {
    onRuntimeInitialized: function () {
        console.log("running ...");
        Module._draw(force_scale, angle);
    }
}
function draw_begin() {
    canvas = $("#my-canvas").get(0);
    ctx = canvas.getContext("2d");
}
function draw_end() {

}
function draw_clear() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
}
function draw_arrow(x1, y1, x2, y2, color) {
    var scale = 0.1;
    var x = (x2 - x1) * scale;
    var y = (y2 - y1) * scale;

    var cx = x2 - x;
    var cy = y2 - y;

    ctx.beginPath();
    ctx.lineWidth = 1;
    ctx.moveTo(x2, y2);
    ctx.lineTo(cx - y/2, cy + x/2);
    ctx.lineTo(cx + y/2, cy + x/2);
    ctx.fillStyle = color;
    ctx.fill();

}
function draw_line(x1, y1, x2, y2, width, color_id, arrow) {
    var color = color_names[color_id];
    ctx.beginPath();
    ctx.lineWidth = width;
    ctx.moveTo(x1, y1);
    ctx.lineTo(x2, y2);
    ctx.strokeStyle = color;
    ctx.stroke();
    if(arrow) {
        draw_arrow(x1, y1, x2, y2, color);
    }
}
function draw_dot(x, y) {
    ctx.beginPath();
    ctx.moveTo(x, y);
    ctx.arc(x, y, 3, 0, 2 * Math.PI, true);
    ctx.fillStyle = "black";
    ctx.fill();
}
function rotate_left() {
    draw_clear();
    angle -= .3;
    Module._draw(force_scale, angle);
}
function rotate_right() {
    draw_clear();
    angle += .3;
    Module._draw(force_scale, angle);
}
function force_up() {
    draw_clear();
    force_scale *= 1.3;
    Module._draw(force_scale, angle)
}
function force_down() {
    draw_clear();
    force_scale /= 1.3;
    Module._draw(force_scale, angle)
}
$(document).keydown(function(e) {
    var arrow = { left: 37, up: 38, right: 39, down: 40 };

    switch(e.which) {
    case arrow.left:
        rotate_left();
        break;
    case arrow.right:
        rotate_right();
        break;
    case arrow.up:
        force_up();
        break;
    case arrow.down:
        force_down();
        break;
    default: return;
    }
    e.preventDefault();
});
