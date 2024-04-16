import React, { useState } from 'react';
import { Amplify } from "aws-amplify";
import { auth } from "aws-amplify";
import  "@aws-amplify/ui-react/styles.css" ;

function SignUpForm() {
  const [formData, setFormData] = useState({
    username: '',
    password: '',
    email: '',
    name: '',
    birthdate: '',
    phone_number: ''
  });

  const { username, password, email, name, birthdate, phone_number } = formData;

  const handleChange = (e) => {
    setFormData({ ...formData, [e.target.name]: e.target.value });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    try {
      const signUpData = {
        username,
        password,
        attributes: {
          email,
          name,
          birthdate,
          phone_number
        }
      };
      await Auth.signUp(signUpData);
      console.log('User signed up successfully');
      // Redirect or show success message
    } catch (error) {
      console.error('Error signing up:', error);
      // Show error message to user
    }
  };

  return (
    <form onSubmit={handleSubmit}>
      <label>
        Username:
        <input type="text" name="username" value={username} onChange={handleChange} required />
      </label>
      <label>
        Password:
        <input type="password" name="password" value={password} onChange={handleChange} required />
      </label>
      <label>
        Email:
        <input type="email" name="email" value={email} onChange={handleChange} required />
      </label>
      <label>
        Name:
        <input type="text" name="name" value={name} onChange={handleChange} required />
      </label>
      <label>
        Birthdate:
        <input type="date" name="birthdate" value={birthdate} onChange={handleChange} required />
      </label>
      <label>
        Phone Number:
        <input type="tel" name="phone_number" value={phone_number} onChange={handleChange} required />
      </label>
      <button type="submit">Sign Up</button>
    </form>
  );
}

function SignInForm() {
  const [formData, setFormData] = useState({
    username: '',
    password: ''
  });

  const { username, password } = formData;

  const handleChange = (e) => {
    setFormData({ ...formData, [e.target.name]: e.target.value });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    try {
      await Auth.signIn(username, password);
      console.log('User signed in successfully');
      // Redirect or show success message
    } catch (error) {
      console.error('Error signing in:', error);
      // Show error message to user
    }
  };

  return (
    <form onSubmit={handleSubmit}>
      <label>
        Username:
        <input type="text" name="username" value={username} onChange={handleChange} required />
      </label>
      <label>
        Password:
        <input type="password" name="password" value={password} onChange={handleChange} required />
      </label>
      <button type="submit">Sign In</button>
    </form>
  );
}

export const AuthForm = () => {
  return (
    <div>
      <h2>Sign Up</h2>
      <SignUpForm />
      <h2>Sign In</h2>
      <SignInForm />
    </div>
  );
};
