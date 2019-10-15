using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public float moveSpeed;


    public float jumpForce;
    public bool grounded;
    public LayerMask whatIsGround;

    private Rigidbody2D myRigidbody;
    private Collider2D myCollider;
    private Animator myAnimator;



    // Start is called before the first frame update
    void Start()
    {
        myRigidbody = GetComponent<Rigidbody2D>();

        myCollider = GetComponent<Collider2D>();

        myAnimator = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        // Checks if player is touching the ground
        grounded = Physics2D.IsTouchingLayers(myCollider, whatIsGround);

        // Gives player horizontal movement
        myRigidbody.velocity = new Vector2(moveSpeed,myRigidbody.velocity.y);

        // Character jumps if space bar is pressed, or left mouse click (will work for tapping on mobile)
        if(Input.GetKeyDown(KeyCode.Space) || Input.GetMouseButtonDown(0))
        {
            // The player will only jump if he is touching the ground
            if (grounded == true)
            {
                myRigidbody.velocity = new Vector2(myRigidbody.velocity.x, jumpForce);
            }


        }

        // Map the variables in the player script to the animation properties
        myAnimator.SetFloat("Speed", myRigidbody.velocity.x);
        myAnimator.SetBool("Grounded", grounded);
        if(myRigidbody.velocity == myRigidbody.velocity)
        {

        }
    }

}
