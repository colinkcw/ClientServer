(function (b) {
    b.fn.labelFader = function () {
        var c = "fade-label-focus";
        var d = function () {
            var f = b(this);
            var e = f.siblings("label").children("span");
            if (f.val()) {
                e.hide()
            } else {
                e.fadeIn(500)
            }
        };
        this.focus(function () {
            d.call(this);
            b(this).parents(".field").addClass(c)
        });
        this.blur(function () {
            d.call(this);
            b(this).parents(".field").removeClass(c)
        });
        this.keyup(d);
        this.keydown(d);
        this.change(d);
        this.each(function () {
            var g = b(this),
                e = g.siblings("label");
            if (e.children().length == 0) {
                var f = b("<span>").text(e.text()).fadeIn();
                e.empty().append(f)
            }
            d.call(this)
        });
        return this
    }
})(jQuery);