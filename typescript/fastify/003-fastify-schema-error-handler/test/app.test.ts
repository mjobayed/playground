import { describe, expect, it } from "vitest";
import app from "../src/app.js";

describe("API test", () => {
  it("Status Check", async () => {
    const response = await app.inject({
      method: "GET",
      url: "/",
    });

    expect(response.statusCode).toBe(200);
    expect(response.json()).toEqual({ message: "OK" });
  });

  it("POST / - Should pass", async () => {
    const response = await app.inject({
      method: "POST",
      url: "/",
      payload: { title: "hello" },
    });

    expect(response.statusCode).toBe(201);
    expect(response.json()).toEqual({ title: "hello" });
  });
});
