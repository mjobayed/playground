import { describe, expect, it } from "vitest";
import app from "../src/app.js";

describe("API test", () => {
  it("GET / - Should return OK", async () => {
    const response = await app.inject({
      method: "GET",
      url: "/",
    });

    expect(response.statusCode).toBe(200);
    expect(response.json()).toEqual({ message: "OK" });
  });

  it("POST / - Should return created", async () => {
    const response = await app.inject({
      method: "POST",
      url: "/",
      payload: { title: "First one" },
    });

    expect(response.statusCode).toBe(201);
    expect(response.json()).toEqual({ title: "First one" });
  });

  it("POST / - Should fail because title is a number", async () => {
    const response = await app.inject({
      method: "POST",
      url: "/",
      payload: { title: 1 },
    });

    expect(response.statusCode).toBe(400);
  });

  it("POST / - Should fail because title is empty", async () => {
    const response = await app.inject({
      method: "POST",
      url: "/",
      payload: { title: "" },
    });

    expect(response.statusCode).toBe(400);
  });
});
