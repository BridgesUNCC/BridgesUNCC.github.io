
var gl;
var indexBuffer;
var indices;

window.onload = function init() {

	var canvas = document.getElementById( "gl-canvas" );
    
	gl = WebGLUtils.setupWebGL( canvas );
	if (!gl) { 
		alert( "WebGL isn't available" ); 
	}

	//
	//  Configure WebGL
	//
	gl.viewport( 0, 0, canvas.width, canvas.height );
	gl.clearColor( 1.0, 1.0, 1.0, 1.0 );

    //  Load shaders and initialize attribute buffers
    
	var program = initShaders( gl, "vertex-shader", "fragment-shader" );
	gl.useProgram( program );

	// convert world coords to NDC


	var vert_wc = [
        [20.,  20.],
        [30.,  20.],
        [30.,  30.],
        [20.,  30.],

        [50.,  20.],
        [60.,  20.],
        [60.,  30.],
        [50.,  30.],

        [20.,  50.],
        [30.,  50.],
        [30.,  60.],
        [20.,  60.],

        [50.,  50.],
        [60.,  50.],
        [60.,  60.],
        [50.,  60.]
    ];
	var vert_colors = [
        [1.,  0., 0., 1.],
        [1.,  0., 0., 1.],
        [1.,  0., 0., 1.],
        [1.,  0., 0., 1.],

        [1.,  0., 0., 1.],
        [1.,  0., 0., 1.],
        [1.,  0., 0., 1.],
        [1.,  0., 0., 1.],

        [1.,  0., 0., 1.],
        [1.,  0., 0., 1.],
        [1.,  0., 0., 1.],
        [1.,  0., 0., 1.],

        [1.,  0., 0., 1.],
        [1.,  0., 0., 1.],
        [1.,  0., 0., 1.],
        [1.,  0., 0., 1.]
	];

	
	indices = [
		[0,1], [1,2], [2, 3], [3,0], [4,5], [5,6], [6,7], [7, 4], 
		[8,9], [9, 10], [10, 11], [11,8], [12,13], [13,14], [14,15], [15,12]
	]; 


	
	var vert_ndc = [];
	var k = 0;
//	for (i = 0; i < vert_wc.length; i++) {
	for (i = 0; i < vertices.length; i++) {
//		vert_ndc[i]= worldToNDC(vert_wc[i], [0.0, 0.0], [100.0, 100.0]);
		vert_ndc[i] = worldToNDC(vertices[i], [range[0], range[2]], [range[1], range[3]]);
	}

    // Load the data into the GPU    
    
    var vBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, vBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, flatten(vert_ndc), gl.STATIC_DRAW);

    // Associate out shader variables with our data buffer
    
    var vPosition = gl.getAttribLocation( program, "vPosition");
    gl.vertexAttribPointer(vPosition, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vPosition);

    var cBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, cBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, flatten(vertex_colors), gl.STATIC_DRAW);

    // Associate out shader variables with our data buffer
    
    var vColor = gl.getAttribLocation( program, "vColor");
    gl.vertexAttribPointer(vColor, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vColor);

	// create the indices into the vertex buffer
	indexBuffer = gl.createBuffer();
	gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, indexBuffer);
	gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, new Uint32Array(flatten(edges)), gl.STATIC_DRAW);
	console.log (flatten(indices));
	console.log("#Edges: " + indices.length);

	gl.getExtension('OES_element_index_uint');
    
	render();
};

function render() {
    gl.clear( gl.COLOR_BUFFER_BIT );

				// draw the square
//	gl.drawElements(gl.LINES, indices.length, gl.UNSIGNED_SHORT, indexBuffer);
	gl.drawElements(gl.LINES, edges.length*2, gl.UNSIGNED_INT, indexBuffer);
/*
    gl.drawArrays(gl.LINES, 0, 8);
    gl.drawArrays(gl.LINES, 8, 8);
    gl.drawArrays(gl.LINES, 16, 8);
    gl.drawArrays(gl.LINES, 24, 8);
*/

}
function worldToNDC(wcoords, wc_min, wc_max) {
	var wc_width = wc_max[0]-wc_min[0];
	var wc_height = wc_max[1]-wc_min[1];
	var ndc_x = ((wcoords[0]-wc_min[0])/wc_width)*2.0 -1.0;
	var ndc_y = ((wcoords[1]-wc_min[1])/wc_height)*(2.0) -1.0 ;

    return [ndc_x, ndc_y];
}

