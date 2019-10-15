using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// Purpose of this script is to move the background as the player moves
public class ScrollingBackground : MonoBehaviour
{
	// Variables we need to track the background layer as well as the number and locations of background pieces
	// Since it is an infinite scroller, we need background movement dependent on the camera as it goes
	public float backgroundSize;

	private Transform cameraTransform;
	private Transform[] layers;
	private float viewZone = 10;
	private int leftIndex;
	private int rightIndex;

	// Initialize our camera following & index each background piece
	private void Start()
	{
		cameraTransform = Camera.main.transform;
		layers = new Transform[transform.childCount];
		for(int i = 0; i < transform.childCount; i++)
			layers[i] = transform.GetChild(i);

		leftIndex = 0;
		rightIndex = layers.Length-1;
	}

	// Invoke scrolling function each time our camera reaches an increment past the right index
	private void Update()
	{
		if(cameraTransform.position.x > (layers[rightIndex].transform.position.x - viewZone))
			ScrollRight();
	}

	//  Essentially takes the leftmost background piece and shifts it in front of far right piece
	private void ScrollRight()
	{
		int lastLeft = leftIndex;
		layers[leftIndex].position = Vector3.right * (layers[rightIndex].position.x + backgroundSize);
		rightIndex = leftIndex;
		leftIndex++;
		if(leftIndex == layers.Length)
			leftIndex = 0;
	}
}
