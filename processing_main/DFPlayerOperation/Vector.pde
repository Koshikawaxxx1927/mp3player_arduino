public class Vector {
  public Vector(int _x, int _y) {
    this._x = _x;
    this._y = _y;
  }
  public Vector get() {
    return this;
  }
  public void set(Vector v) {
    this._x = v._x;
    this._y = v._y;
  }
  public Vector add(Vector v) {
    return new Vector(this._x + v._x, this._y + v._y);
  }
  public Vector subtract(Vector v) {
    return new Vector(this._x - v._x, this._y - v._y);
  }
  public Vector multiply(Vector v) {
    return new Vector(this._x * v._x, this._y * v._y);
  }
  public Vector divide(Vector v) {
    return new Vector(this._x / v._x, this._y / v._y);
  }
  public Vector add(int v) {
    return add(new Vector(v, v));
  }
  public Vector subtract(int v) {
    return subtract(new Vector(v, v));
  }
  public Vector multiply(int v) {
    return multiply(new Vector(v, v));
  }
  public Vector divide(int v) {
    return divide(new Vector(v, v));
  }
  public int x() {
    return this._x;
  }
  public int y() {
    return this._y;
  }
  
  private int _x;
  private int _y;
}
