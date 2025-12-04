static void
seladjust(int delta)
{
	if (sel.ob.x == -1)
		return;

	if (sel.alt != 0)
		return;

	sel.ob.y += delta;
	sel.oe.y += delta;

	selnormalize();
	tsetdirt(sel.nb.y, sel.ne.y);
}

void
kscrolldown(const Arg* a)
{
	int n = a->i;

	if (n < 0)
		n = term.row + n;

	if (n > term.scr)
		n = term.scr;

	if (term.scr > 0) {
		term.scr -= n;
		seladjust(-n);
		tfulldirt();
		draw();
	}

	scroll_images(-1*n);

}

void
kscrollup(const Arg* a)
{
	int n = a->i;
	if (n < 0)
		n = term.row + n;

	if (term.scr + n > term.histn)
		n = term.histn - term.scr;

	if (!n)
		return;

	if (term.scr <= HISTSIZE-n) {
		term.scr += n;
		seladjust(n);
		tfulldirt();
		draw();
	}

	scroll_images(n);

}
