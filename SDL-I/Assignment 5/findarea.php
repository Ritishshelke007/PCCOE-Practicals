<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
  
<form method="post" action="" class="form">

<div class="first">
<label class="particles-checkbox-container">
  <input type="radio" class="particles-checkbox" name="shape" value="triangle" onclick="showParameters('triangle')">
  <span>Triangle</span>
</label>

<label class="particles-checkbox-container">
  <input type="radio" class="particles-checkbox" name="shape" value="square" onclick="showParameters('square')">
  <span>Sqaure</span>
</label>

<label class="particles-checkbox-container">
  <input type="radio" class="particles-checkbox" name="shape" value="circle" onclick="showParameters('circle')">
  <span>Circle</span>
</label>
</div>

<div class="second">
<div class="shape-parameters" id="triangle-params">
        Base: <input type="text" name="base" class="parameter"><br>
        Height: <input type="text" name="height" class="parameter"><br>
    </div>

    <div class="shape-parameters" id="square-params">
        Side: <input type="text" name="side" class="parameter"><br>
    </div>

    <div class="shape-parameters" id="circle-params">
        Radius: <input type="text" name="radius" class="parameter"><br>
    </div>

    <button type="submit" class="btn" style="margin-top: 10px; margin-bottom:20px;">Calculate</button>

    <?php

class Shape {
    protected $name;

    public function __construct($name) {
        $this->name = $name;
    }

    public function getName() {
        return $this->name;
    }

    public function calculateArea() {
        // Base class method, to be overridden by subclasses
        return 0;
    }
}

class Triangle extends Shape {
    private $base;
    private $height;

    public function __construct($base, $height) {
        parent::__construct("Triangle");
        $this->base = $base;
        $this->height = $height;
    }

    public function calculateArea() {
        return 0.5 * $this->base * $this->height;
    }
}

class Square extends Shape {
    private $side;

    public function __construct($side) {
        parent::__construct("Square");
        $this->side = $side;
    }

    public function calculateArea() {
        return $this->side * $this->side;
    }
}

class Circle extends Shape {
    private $radius;

    public function __construct($radius) {
        parent::__construct("Circle");
        $this->radius = $radius;
    }

    public function calculateArea() {
        return M_PI * $this->radius * $this->radius;
    }
}

if (isset($_POST['shape'])) {
    $selectedShape = $_POST['shape'];

    switch ($selectedShape) {
        case 'triangle':
            $triangle = new Triangle($_POST[ 'base'], $_POST['height']);
            echo "Area of " . $triangle->getName() . ": " . $triangle->calculateArea();
            break;

        case 'square':
            $square = new Square($_POST['side']);
            echo "Area of " . $square->getName() . ": " . $square->calculateArea();
            break;

        case 'circle':
            $circle = new Circle($_POST['radius']);
            echo "Area of " . $circle->getName() . ": " . $circle->calculateArea();
            break;

        default:
            echo "Please select a shape.";
            break;
    }
}

?>
</div>

</form>







</body>

<script>
    function showParameters(shape) {
        // Hide all shape parameter divs
        document.querySelectorAll('.shape-parameters').forEach(function (div) {
            div.style.display = 'none';
        });

        // Show the selected shape parameter div
        document.getElementById(shape + '-params').style.display = 'block';
    }
</script>
</html>
